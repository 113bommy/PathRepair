n = int(input());

x = 2;

for i in range(2, n + 2):
    m = i * (i - 1);
    print(int((m * m - x) / (i - 1)));
    x = m;