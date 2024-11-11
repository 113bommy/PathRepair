i = lambda : map ( int , input().split() ) 
n , m = i()  

difference = []
sumOverall = 0 
sumCompressed = 0 
for _ in range (n) :
       first , last = i() 
       sumOverall += first 
       sumCompressed += last 
       difference.append( first - last ) 

if sumOverall <= m : 
       print ( 0 ) 
elif sumCompressed > m :
       print ( -1 ) 
else :
       count = 0 
       difference.sort( reverse = True ) 
       for i in range ( len(difference) ) :
              sumOverall -= difference[i] 
              count += 1 
              if ( sumOverall <= m ) :
                     break 
       
       print ( count ) 

