t = int(input())
for i in range(0, t):
  s = input()
  s = s.lower()
  flag = True
  count = [0]*26
  if len(s) == 0 or len(s) > 26: print("No")
  else:
    for j in range(0, len(s), 1):
      #     print(j, s[j], ord(s[j]))
      if(count[ord(s[j]) - ord('a')] == 0):
        count[ord(s[j]) - ord('a')] += 1
      else:
        flag = False
        break
    setflag = False
    if flag is True:
      for j in range(0,26,1):
        if count[j] == 0 and j!=0 and count[j-1] == 1:
          setflag = True
        if setflag is True:
          if count[j] == 1:
            flag = False
            break
    if flag==True:
      print("Yes")
    else:  
      print("No")
