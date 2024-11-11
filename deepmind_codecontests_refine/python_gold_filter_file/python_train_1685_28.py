t=int(input())
for i in range(t):
      n=int(input())
      a=list(map(int,input().split()))
      cnt=0
      a=a[::-1]
      #print(a)
      min=a[0]
      for i in a:
            if i > min:
                  cnt+=1
            else:
                  min=i
      print(cnt)