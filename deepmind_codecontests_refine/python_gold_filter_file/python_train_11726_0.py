h=int(input())
l=list(map(int,input().split()))
x=False
pos=0
s=1
for i in range(h):
      if (l[i]!=1) and (l[i+1]!=1) :
            pos=i+1
            x=True
            print("ambiguous")
            break
if not x:
      print("perfect")
else:
      ch="0"
      ch1="0"
      for i in range(1,len(l)):
            ch+=(" "+str(s))*l[i]
            if i!=pos:
                  ch1+=(" "+str(s))*l[i]
            else:
                  ch1+=" "+str(s-1)+(" "+str(s))*(l[i]-1)
            s+=l[i]
      print(ch)
      print(ch1)