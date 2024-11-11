for _ in range(int(input())):
  j=int(input())
  s=input()
  if len(s)!=2:
    print('YES')
    print(2)
    print(s[0],s[1:])
  else:
    if int(s[0])>=int(s[1]):
      print('NO')
    else:
      print('YES')
      print(2)
      print(s[0],s[1])