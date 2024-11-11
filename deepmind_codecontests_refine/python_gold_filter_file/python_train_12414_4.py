import sys
input = sys.stdin.readline

N, A, R, M = map(int, input().split())
H = list(map(int, input().split()))

def get(l):
    over = 0
    under = 0
    for h in H:
        if h > l:
            over += h-l
        else:
            under += l-h
    if A+R <= M:
        return over*R + under*A
    elif over < under:
        return over*M + (under-over)*A
    else:
        return under*M + (over-under)*R
    
l1 = -1
l2 = 10**9+1
ans = 10**18
while 2 < l2-l1:
    m1 = (2*l1+l2)//3
    m2 = (l1+2*l2)//3
    s_m1 = get(m1)
    s_m2 = get(m2)
    ans = min(ans, s_m1)
    ans = min(ans, s_m2)
    if s_m1 >= s_m2:
        l1 = m1
    else:
        l2 = m2
for i in range(l1-5, l2+5):
    ans = min(ans, get(i))
print(ans)