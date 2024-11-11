#  Precondition: d1 < d2
def possible(d1,h1,d2,h2):
    if (d2-d1 < abs(h2-h1)):
        return -1
    elif h1==h2:
        return (d2-d1)//2 + h1
    elif h1 > h2:
        diff = h1 - h2
        newd2 = d2 - diff
        if newd2 < d1:
           return -1
        else:
           return (newd2-d1)//2 + h1
    else:  # h1 < h2
        diff = h2 - h1
        newd1 = d1+diff
        if newd1 > d2:
            return -1
        else:
            return (d2-newd1)//2 + h2

# print ("Input n and m (days and notes)")
info = input().split()
n = int(info[0])
m = int(info[1])

# print ("Input first day/height pair")
first = input().split()
oldd = int(first[0])
oldh = int(first[1])
answer = (oldd-1) + oldh  # Compute what day one could be

bad = False
for i in range(m-1):
    # print ("Input next day/height pair")
    inf = input().split()
    newd = int(inf[0])
    newh = int(inf[1])
    pos = possible(oldd, oldh, newd, newh)
    if (pos == -1):
        print ("IMPOSSIBLE")
        bad = True
        break
    else:   #  Can do it--check to see if a greater height
        if pos > answer:
            answer = pos
    oldd = newd
    oldh = newh

#  If we are still OK, compute what the last day could be
if (not bad):
    endheight = (n - oldd) + oldh
    if endheight > answer:
        answer = endheight
    print (answer)
        
        
    
    


        
       
