n = int (input ())
s = input ().strip ()
dic = {}
for i in range (n):
    if s [i] not in dic:
        dic [s [ i]] = 1
        continue
    dic [ s [i] ] += 1
e = dic.get ('e', 0)
r = dic.get ('r', 0)
n = dic.get ('n', 0) 
o =  dic.get('o', 0)
z = dic.get('z', 0)
tmp1 = min (e ,r  ,z ,o)
tmp2 = min (o - tmp1,n , e - tmp1)
for j in range (tmp2):
    print (1, ' ')
for k in range (tmp1):
    print (0, ' ')
