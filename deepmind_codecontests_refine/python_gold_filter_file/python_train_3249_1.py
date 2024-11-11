num = int(input());
years = [];

for i in range(0, num):
    years.append(int(input()));


for i in range(0, num):
    rs = 0;
    k = [];
    bck = years[i];
    while years[i] >= 10: 
        k.append(years[i] % 10);
        years[i] = years[i]//10;
    k.append(years[i]);

    leng = len(k);
    rs = 9*(leng-1);
    
    j = leng-1;
    rs += k[j]-1;
    maxx = k[j];

    
    for i in range(0, j):
        maxx *= 10;
        maxx += k[j];
    
    if bck >= maxx:
        rs+=1;

    
    print(rs);
