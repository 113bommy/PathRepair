n=int(input())
li=[]
def value(a):
  if a=='rat':
    return 1
  elif a=='woman' or a=='child':
    return 2
  elif a=='man':
    return 3
  elif a=='captain':
    return 4
  else : 
    return 5 

i=0
for i in range(n):
  (name,prio)=tuple(input().split(" "))
  nihaw=value(prio)
  li.append((nihaw,i,name))
  i=i+1
li.sort()
for i in li:
  print(i[2])
