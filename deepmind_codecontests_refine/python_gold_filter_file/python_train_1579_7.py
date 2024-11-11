

n = int(input())
i = 0

listi = list      ( map  (int, input().split()) )

ones = listi.count(1);
twos = listi.count(2);

#print("1s 2s ", ones, twos)

if (ones >= 1 and twos >= 1):
    print('2 ' + '1 ' + '2 ' * (twos-1) + '1 ' * (ones-1))
else:
    print(' '.join(map(str, listi)))