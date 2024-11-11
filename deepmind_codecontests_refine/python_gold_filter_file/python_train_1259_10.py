from string import ascii_lowercase

t = int(input())
abc = ascii_lowercase[:27]
for _ in range(t):
    midd = int(int(input())/2)
    scd = input()
    fst = scd[:midd]
    scd = scd[::-1][:midd]
    is_palin = True
    for i in range(midd):
        l1, l2 = fst[i], scd[i]
        is_palin &= (abs(ord(l1)-ord(l2)) in {0,2})
    if is_palin:
        print('YES')
    else:
        print('NO')
