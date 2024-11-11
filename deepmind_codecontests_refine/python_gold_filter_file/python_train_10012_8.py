for n in range(int(input())):
  j=int(input())
  s=sorted(list(map(int,input().split())))
  s=s[::-1]
  if j<3:
    print(0)
  else:
    print(min(s[1]-1,j-2))
      