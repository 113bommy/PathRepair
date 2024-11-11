n=int(input())
m=list(map(int,input().split()))
a,b=0,0
for i in m:
     if i==1:
          a+=1
     else:
          b+=1
if a>=3:
     print("1 1 1 "+"2 "*b+"1 "*(a-3))
elif a==2 and b>0:
     print("2 "+"1 "+"2 "*(b-1)+"1")
elif a==2 and b==0:
     print("1 1")
elif a==1 and b>0:
     print("2 1 "+"2 "*(b-1))
elif a==1 and b==0:
     print(1)
elif a==0:
     print("2 "*b)