a,b,c,d,e,f = map(int, input().split())
ans = [-1,0,0]
for i in range(f//(a*100)+1):
  for j in range((f-a*100*i)//(b*100)+1):
    for k in range((f-a*i*100-b*j*100)//c+1):
      for l in range((f-a*i*100-b*j*100-c*k)//d+1):
        w = i*a+j*b
        s = k*c+l*d
        if w == 0:
          continue
        if w*e >= s and ans[0] < s/(w*100+s):
          ans = [s/(w*100+s),w*100+s,s]
print(ans[1],ans[2])
