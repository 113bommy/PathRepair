

s1 = input()
s1 = s1.lower()
s2 = input()
s2 = s2.lower()

count = 0

if (len(s1) <= 100000 and len(s2) <= 30) and (len(s1) and len(s2)) >= 1 :
    count = s1.count(s2)
print(count)

    
