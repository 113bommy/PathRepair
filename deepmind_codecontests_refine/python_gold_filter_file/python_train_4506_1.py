
t=int(input())
while (t):
    t-=1
    
    s1,s2,s3=map(int,input().split())
    
    c1=max(s1,s3)-min(s1,s3)
    print(int((c1**2+s2**2)**(1/2)))
