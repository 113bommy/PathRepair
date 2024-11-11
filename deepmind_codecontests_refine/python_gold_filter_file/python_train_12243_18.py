h,m=map(int,input().split(':'))
i=0
while h//10!=m%10 or h%10!=m//10:
    i,m = i+1, m+1
    if m>=60:
        m=0
        h+=1
    h%=24
print(i)