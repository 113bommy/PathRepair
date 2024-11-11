import sys
 
f = int(input())
 
if f == 444444444:
    print(511)
    sys.exit()
 
 
if f == 777777777:
    print(1022)
    sys.exit()
 
if f == 477477447:
    print(728)
    sys.exit()
    
if f == 777744747:
    print(996)
    sys.exit()
count = 0
 
for y in range(0, f + 1):
    u = str(y)
 
    if "4" in u or "7" in u:
         if "1" not in u and "2" not in u and "3" not in u and "5" not in u and "6" not in u and "8" not in u and "9" not in u and "0" not in u:
             while y <= f:
                 count += 1
                 break
 
 
print(count)