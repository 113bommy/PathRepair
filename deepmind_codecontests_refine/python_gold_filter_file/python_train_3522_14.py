def f():
  n=int(input())
  l=tuple(tuple(map(int,input().split())) for i in range(n-1))
  for i in range(n):
    now=0
    for a,s,d in l[i:]:
      now=a+s-(-max(0,now-s)//d)*d
    print(now)
if __name__=="__main__":
  f()