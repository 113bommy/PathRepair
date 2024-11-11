a,b,c,d,e,f=map(int,input().split())
ans=[100*a,0]
for i in range(f//(100*a)+1):
  for j in range((f-100*a*i)//(100*b)+1):
    for k in range(f//c+1):
      if i==0 and j==0:
        break
      for l in range((f-c*k)//d+1):
        if 100*a*i+100*b*j+c*k+d*l>f:
          break
        elif c*k+d*l>(a*i+b*j)*e:
          break
        else:
          if (c*k+d*l)/(100*a*i+100*b*j+c*k+d*l)>ans[1]/ans[0]:
            ans=[100*a*i+100*b*j+c*k+d*l,c*k+d*l]
print(ans[0],ans[1])