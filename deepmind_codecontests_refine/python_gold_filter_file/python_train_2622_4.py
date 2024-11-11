for t in range(int(input())):
    s = input()
    count = 0
    x = s.count('0')
    if x == len(s):
        print(0)
        continue
   # x = s.index('1')
    last = 0
    for i in range(len(s)):
        val = 0
        if s[i] == '1':
            for j in range(i, min(i+18,len(s))): 
                if s[j] == '0':
                    val *= 2
                else:
                    val = val*2 + 1
                if val <= j-last+1:
                    count += 1
                    #print(j, i, val, last)

            last = i+1
    print(count)