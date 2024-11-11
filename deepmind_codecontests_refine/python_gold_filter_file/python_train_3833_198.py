a,b,c=map(int,input().split())
print(b+c if c-b<=a+1 else b+c-(c-b-a)+1)