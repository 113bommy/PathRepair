n = int(input())
ss = []
for i in range(n):
    ss.append(input())
for i in range(n):
    s= ss[i]
    f = [ord(a) for a in s]
    s_even = sorted([x for x in f if x % 2 == 0])
    s_odd = sorted([x for x in f if x % 2 == 1])
    if s_even == []:
        print(''.join(map(chr, s_odd)))
    elif s_odd == []:
        print(''.join(map(chr, s_even)))
    else:
        if s_even[-1] - s_odd[0] ==1 or s_even[-1]-s_odd[0] == -1:
            if s_odd[-1] - s_even[0] ==1 or s_odd[-1]-s_even[0] == -1:
                print('No answer')
            else:
                print(''.join(map(chr, s_odd + s_even)))
        else:
            print(''.join(map(chr, s_even + s_odd)))
    


