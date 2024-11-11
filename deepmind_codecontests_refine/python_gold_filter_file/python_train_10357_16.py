s = input()
a = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
if int(s) == 0:
    print('zero')
elif int(s) < 20:
    print(a[int(s)-1])
elif int(s) >= 80 and int(s) < 90:
    print('eighty', end = '')
    if int(s) != 80:
        print('-', a[int(s[1])-1], sep = '')
elif int(s) >= 50 and int(s) < 60:
    print('fifty', end = '')
    if int(s) != 50:
        print('-', a[int(s[1])-1], sep = '')
elif int(s) >= 40 and int(s) < 50:
    print('forty', end = '')
    if int(s) != 40:
        print('-', a[int(s[1])-1], sep = '')
else:
    n = int(s)
    if n > 39:
        if n % 10 == 0:
            print(a[int(s[0])-1], 'ty', sep = '')
        else:
            print(a[int(s[0]) - 1] ,'ty' , '-' , a[int(s[1])-1], sep ='')
    else:
        if n < 30:
            print('twenty', end = '')
            if n % 10 != 0:
                print('-', a[int(s[1])-1], sep = '')
        else:
            print('thirty', end = '')
            if n % 10 != 0:
                print('-', a[int(s[1])-1], sep = '')