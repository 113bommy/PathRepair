import math
t1,t2 = map(int,(input().split(' ')))
a1,a2 = map(int,(input().split(' ')))
b1,b2 = map(int,(input().split(' ')))
n = t1*a1+t2*a2
m = t1*b1+t2*b2
if(n==m):
    print("infinity")
    exit(0)
ans1 = max(0,math.ceil((b1-a1)*t1/(n-m)))
ans2 = max(0,math.ceil((t1*(b1-a1)+t2*(b2-a2))/(n-m))-1)
#if((t1*(b1-a1))%(n-m) == 1):
#    ans3 = 1
#else:
#    ans3 = 0
ans3 = max(0,math.floor(t1*(b1-a1)/(n-m))+1)
print(max(ans1+ans2+ans3-1,0))