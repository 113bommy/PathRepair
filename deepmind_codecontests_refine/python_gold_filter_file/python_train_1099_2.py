n = (int) (input ());
if n == 0: 
    print (1);
else:
    if n % 4 == 0:
        print (6);
    else:
        if n % 4 == 1:
            print (8);
        else:
            if n % 4 == 2:
                print (4);
            else:
                print (2);