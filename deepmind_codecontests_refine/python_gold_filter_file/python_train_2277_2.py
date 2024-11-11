import re

lst=0
try:
 while True:
  x=input()
  for i in re.findall(r'\d+',x):
      lst+=int(i)
except:
   print(lst)