t=int(input())
if 1<=t<=10**5:
       for i in range(t):
              a=input().split()
              a[0]=int(a[0])
              a[1]=int(a[1])
              
              if (a[1]%2==0 and a[0]%2==0) or (a[1]%2!=0 and a[0]%2!=0):
                     if a[0]>=a[1]**2:
                            print("YES")
                     else:
                            print("NO")
              else:
                     print("NO")