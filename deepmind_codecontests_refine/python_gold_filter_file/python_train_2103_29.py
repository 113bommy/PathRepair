querries=int(input())
for querrie in range(querries):
  pens=0
  pencils=0
  abcdk=input().split(" ")
  for num in range(5):
    abcdk[num]=int(abcdk[num])
  while abcdk[2]*pens<abcdk[0]:
    pens=pens+1
  while abcdk[3]*pencils<abcdk[1]:
    pencils=pencils+1
  if pens+pencils>abcdk[4]:
    print("-1")
  else:
    print(pens,pencils)