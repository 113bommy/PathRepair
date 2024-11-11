n=int(input())
ans=0
for i in range(5,int(n**0.5)+1):
    if(n%i==0):
        if(n/i>=5):
            ans = i
            break
if(ans == 0):
    print('-1')

else:
    s=0
    s1=0
    b =['a','e','i','o','u']
    for i in range(int(n/ans)):
        s =s1
        s1=(s1+1)%5
        for j in range(ans):
            print(b[s],end='')
            s = (s+1)%5