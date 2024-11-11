s = list(map(int, input().split()))
if len(set(s)) > 3:
    print('Alien')
else:
    k = False
    for element in s:
        if s.count(element) >= 4:
            k = True
            n = element
            
    if k != True:
        print('Alien')
    else:
        for i in range(4):
            s.remove(n)
            
        if s[0] == s[1]:
            print('Elephant')
        else:
            print('Bear')
            