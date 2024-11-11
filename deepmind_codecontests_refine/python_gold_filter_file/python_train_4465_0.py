n = int(input())

for _ in range(n):
    train = ''
    seq = input()
    for i in range(0, len(seq), 3):
        if i == 0:
            train += seq[i]
        if seq[i - 2:i] == '->' and train[-1] == seq[i - 3]:
            train = train + seq[i]
        if seq[i - 2:i] == '<-' and train[0] == seq[i - 3]:
            train = seq[i] + train
    print(train)

