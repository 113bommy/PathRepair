n=int(input())
a=int(input())
b=int(input())
if a==b and n%a!=0:
  print('NO')
elif n%a==0:
    print('YES')
    print(n//a,end=' ')
    print(0)
elif n%b==0:
    print('YES')
    print('0',end=' ')
    print(n//b)

elif n%2==1 and a%2==0 and b%2==0:
  print('NO')
elif max(a,b)%min(a,b)==0 and n%a!=0 and n%b!=0:
  print('NO')
elif a+b>n:
  print('NO')
else:
    i=0
  
    if a>b:
      while i<=n//a and (n-a*i)%b!=0:
        i=i+1
      if i>n//a:
        print('NO')
      else:
        print('YES')
        print(i,end=' ')
        print((n-a*i)//b)
    else:
      while i<=n//b and (n-b*i)%a!=0:
        i=i+1
      if i>n//b:
        print('NO')
      else:
        print('YES')
        print((n-b*i)//a,end=' ')
        print(i)
