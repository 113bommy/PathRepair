N = int(input())
R = [int(i) for i in input().split()]
S = set()
f = 0
for i in R:
    if i//400 < 8:
        S.add(i//400)
    else:
        f += 1

t = max(1,len(S)) 
mx = len(S)+f
print(t,mx)
