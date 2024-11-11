k=int(input())
n=0
s='aeiou'
s1=''
for i in range(5,k):
    if k%i==0:
        n=i
        break
if n==0:
    print(-1)
else:
    m=k//n
    if m<5:
        print(-1)
    else:
        for i in range(n):
            x=m//5
            y=m%5
            s1=s*x
            s1=s1+s[:y]
            print(s1,end='')
            s=s[-1]+s[0:-1]