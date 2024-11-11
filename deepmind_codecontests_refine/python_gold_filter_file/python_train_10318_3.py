n=int(input())
arr=list(map(int,input().split()))
d={}
ans=['A']*n
for i in range(n):
  if arr[i] in d:
    d[arr[i]].append(i)
  else:d[arr[i]]=[i]
flag=False
s='A'
cnt=0
sec_arr=[]
for i in d.keys():
  if len(d[i])==1:
    cnt+=1
    a=d[i]
    if s=='A':
      s='B'
      continue
    else:
      ans[a[0]]=s
      s='A'
  elif len(d[i])>2:
     sec_arr=d[i]
     
  
    
if cnt%2==0:
  print('YES')
  print(''.join(ans))
elif cnt%2==1 and len(sec_arr)>0:
   print('YES')
   ans[sec_arr[0]]='B'
   print(''.join(ans))
else:
  print('NO')
