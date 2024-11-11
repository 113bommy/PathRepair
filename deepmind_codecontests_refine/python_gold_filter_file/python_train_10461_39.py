li = list(map(int,input().strip().split()))
total=li[1]
for i in range(li[2]):
    total -= li[0]*(i+1)

if(total<0):
    print(-total)
else:
    print(0)