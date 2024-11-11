n=int(input())
if n==3:
  print(2,5,63)
else:
  if n%2==0:
    ans=[3,9]
    cnt=2
    for i in range(30001):
      if i%6==2:
        if i+2<=30000:
          ans.append(i)
          ans.append(i+2)
          cnt+=2
          if cnt==n:
            break
      else:
        continue
    if cnt<n:
      for i in range(12,30001):
        if i%12==3:
          if i+9<=30000:
            ans.append(i)
            ans.append(i+6)
            cnt+=2
            if cnt==n:
              break
        else:
          continue
    if cnt<n:
      for i in range(1,30001):
        if i%6==0:
          ans.append(i)
          cnt+=1
          if cnt==n:
            break
    print(*ans)
  else:
    ans=[3,6,9]
    cnt=3
    for i in range(30001):
      if i%6==2:
        if i+2<=30000:
          ans.append(i)
          ans.append(i+2)
          cnt+=2
          if cnt==n:
            break
      else:
        continue
    if cnt<n:
      for i in range(12,30001):
        if i%12==3:
          if i+9<=30000:
            ans.append(i)
            ans.append(i+6)
            cnt+=2
            if cnt==n:
              break
        else:
          continue
    if cnt<n:
      for i in range(7,30001):
        if i%6==0:
          ans.append(i)
          cnt+=1
          if cnt==n:
            break
    print(*ans)