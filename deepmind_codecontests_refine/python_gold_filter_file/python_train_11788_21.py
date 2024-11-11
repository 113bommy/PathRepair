for i in range (int (input ())):
    s = input ().strip ()
    li_s = [int (i) for i in s]
    first = s.find ('1')
    last =len (s) -  s [::-1].find ('1') - 1
    if first == -1 or last == -1:
        print (0)
        continue
    print ( (last - first) + 1 -sum (li_s))
