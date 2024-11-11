t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    a_sum = 0
    a_xor = 0
    for x in a:
        a_sum += x
        a_xor ^= x

    if a_sum == 2 * a_xor:
        print(0)
        print()
    else:
        b1 = a_xor

        a_sum += b1
        a_xor ^= b1
        
        assert a_sum % 2 == 0
        assert a_xor == 0

        p = 1
        while p <= a_sum:
            p *= 2
            
        #print(f'SUM {a_sum:b}')
        #print(f'XOR {a_xor:b}')
        #print(f'p   {p:b}')
        b1 += p
        b2 = 0
        a_sum += p
        a_xor = p

        i = 1
        while i <= p:
            if a_sum % (2*i):
                b2 += i // 2
                a_sum += i
            i *= 2
        #print(f'SUM {a_sum:b}')
        #print(f'XOR {a_xor:b}')
        #print(f'p   {p:b}')

        print('3')
        print(b1, b2, b2)

        a_sum = 0
        a_xor = 0
        for x in a + [b1, b2, b2]:
            a_sum += x
            a_xor ^= x

        assert a_sum == 2 * a_xor
