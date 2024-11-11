l=[]

for x in ['S','H','C','D']:
    for y in [str(i+1) for i in range(13)]:
        l += [x+' '+y]

for n in range(int(input())):
  l.remove(input())
for i in l:
  print(i)