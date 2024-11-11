a, ta = map(int, input().split())
b, tb = map(int, input().split())

c, d = map(int, input().split(':'))
mins = (c-5)*60 + d

buses = [i*b for i in range(2000)]

st = mins - tb
end = mins + ta
ans = 0
for el in buses:
    if el>st:ans+=1
    if el>=end or el>=19*60:
        ans-=1;break
print(ans)