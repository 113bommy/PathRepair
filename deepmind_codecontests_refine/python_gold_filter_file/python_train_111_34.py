n = int(input())
a = list(map(int, input().split()))
e = sum(a)

def check(m, ar):
    s = 0
    for i in ar:
        s += m-i
        
    return s

st = max(a)
while check(st, a) <= e:
    st += 1
    
print(st)