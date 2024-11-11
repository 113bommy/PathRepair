

k = input()

posn = k.index(':')

kb = k[:posn]
ka = k[posn+1:]

count = 0
while True:




 if int(kb) < 23:
    if int(ka) < int(kb[::-1]) and count == 0 and int(kb[::-1])< 60 and len(kb) == 2:

            print(kb+':'+kb[::-1])
            break

    else:
        kb = str(int(kb)+1)
        count+=1
        if int(kb[::-1])< 60 and len(kb) == 2 and int(kb) > 5:

          print(kb+':'+kb[::-1])
          break
        elif int(kb[::-1])< 60 and int(kb) <=5:

            print('0' + kb+':'+kb[::-1] + '0')
            break



 else:

    if int(ka) < int(kb[::-1]) and len(kb) == 2:
        print(kb+':'+kb[::-1])
        break

    else:
        kb = str(int(kb)+1)
        print('00'+':'+'00')
        break
