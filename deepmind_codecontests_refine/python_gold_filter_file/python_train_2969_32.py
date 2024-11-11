weeks=[52,52,52,52,53,53,52]
months=[12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,12,11,7]
s=list(input().split(" "))
no=int(s[0])
if(s[2]=='week'):
  print(weeks[no-1])
else:
  print(months[no-1])