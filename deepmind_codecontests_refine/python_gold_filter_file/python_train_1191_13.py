n = int(input())
a = list(map(int, input().split()))

if len(a) > 1:

    dec = a[0] > a[1]
    dec_count = 0
    if dec:
        dec_count += 1
        dec_start = 0

    for i in range(n-1):
        if a[i] > a[i+1]:
            if dec:
                continue
            else:
                dec = True
                
                dec_start = i
                dec_count += 1
                if dec_count > 1:
                    break
        else:
            if dec:
                dec = False
                dec_end = i
                
                if a[dec_start] > a[i+1]:
                    dec_count += 1
                if dec_start > 0 and a[dec_end] < a[dec_start-1]:
                    dec_count += 1
            else:
                continue

    if dec:
        dec_end = n-1
        if dec_start > 0 and a[dec_end] < a[dec_start-1]:
            dec_count += 1
    
    if dec_count == 0:
        print('yes')
        print('1 1')
    elif dec_count == 1:
        print('yes')
        print(str(dec_start+1) + ' ' + str(dec_end+1))
    else:
        print('no')
else:
    print('yes')
    print('1 1')

