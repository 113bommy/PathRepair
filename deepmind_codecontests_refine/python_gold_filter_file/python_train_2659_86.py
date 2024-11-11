n,h=map(int,input().split())
print(sum([2 if int(i)>h else 1  for i in input().split() ]))