n,a,b = map(int,input().split())
s = list(map(int,input().split()))
summ = sum(s)
first = s[0]
curr = (s[0]*a)/summ
if curr >= b:
    print(0)
else:
    s.pop(0)
    s.sort(reverse=True)
    i = 0
    c = 0
    while curr < b and i <= n-2:
        # print("curr",curr)
        summ -= s[i]
        c += 1
        curr = (first*a)/summ
        i += 1
    print(c)