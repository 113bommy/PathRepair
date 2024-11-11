T1,T2=[int(i) for i in input().split()]
A1,A2=[int(i) for i in input().split()]
B1,B2=[int(i) for i in input().split()]
if((B1-A1)*((B1-A1)*T1+(B2-A2)*T2)>0):
  print(0);
  exit();
if((B1-A1)*T1+(B2-A2)*T2==0):
  print("infinity")
  exit();
ans=(abs((B1-A1)*T1)//abs((B1-A1)*T1+(B2-A2)*T2))*2+1
if(abs((B1-A1)*T1)%abs((B1-A1)*T1+(B2-A2)*T2)==0):
  ans-=1
print(ans)

