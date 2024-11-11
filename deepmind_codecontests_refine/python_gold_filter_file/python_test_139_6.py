f=int(input())
for i in range(f):
  n=input()
  if(len(n)%2!=0):
    print("NO")
  else:
    l=list(n)
    h=[]
    s=""
    l=len(n)
    t=l//2
    for i in range(t):
      h.append(n[i])
    s=s.join(h)
    if (n[t:].find(s) == -1):
        print("NO")
    else:
        print("YES")