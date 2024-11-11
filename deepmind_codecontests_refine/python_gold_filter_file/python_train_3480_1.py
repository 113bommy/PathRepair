import math
from collections import Counter
max_sec, a, divNum, capa, whole, sec, boxes, hap= 0, 0, 0, 0,(input()), int(0), int(0), True
who=whole.split(" ")
max_sec, a, divNum, capa=int(who[0]), int(who[1]), int(who[2]), int(who[3])

while(a>0):
      if(a<=capa):
         boxes+=1
         a-=a
         break
      if(max_sec*capa<a and max_sec<=divNum and sec!=max_sec):
        a-=(capa*max_sec)
        sec+=max_sec
        divNum-=(max_sec-1)
      elif(sec!=max_sec):
        while(divNum!=0 and sec!=max_sec):
          a-=capa
          divNum-=1
          sec+=1
      if(divNum==0):
        a-=capa
        boxes+=1
      if(sec==max_sec):
        boxes+=1
        sec=0 
print(boxes)