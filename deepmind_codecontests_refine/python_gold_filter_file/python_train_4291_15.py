


def main():
    nos = int(input())

    p = input()
    pattern = list(p)
    bcount = pattern.count('B')
    wcount = pattern.count('W')

    if bcount%2 != 0 and wcount%2 != 0:
        print(-1)
        return 0
    count  = 0
    steps = []
    if bcount%2 == 0:
        i = 0
        while i< len(pattern)-1 :
            if (pattern[i] == 'B' and pattern[i+1] == 'W') :
                count += 1
                steps.append(i+1)
                temp = pattern[i]
                pattern[i] = pattern[i+1]
                pattern[i+1] = temp
                i += 1
            elif pattern[i] == pattern[i+1]:
                i+=2
            else:
                i +=1
        i = 0
        for i in range(len(pattern)-1):
            if (pattern[i] == 'B' and pattern[i+1] == 'B'):
                count += 1
                pattern[i] = 'W'
                pattern[i+1] = 'W'
                steps.append(i+1)
    else:
        i = 0
        while i< len(pattern)-1 :
            if (pattern[i] == 'W' and pattern[i+1] == 'B'):
                count += 1
                steps.append(i+1)
                temp = pattern[i]
                pattern[i] = pattern[i+1]
                pattern[i+1] = temp
                i += 1
            elif pattern[i] == pattern[i+1]:
                i+=2
            else:
                i +=1

        for i in range(len(pattern)-1):
            if (pattern[i] == 'W' and pattern[i+1] == 'W'):
                count += 1
                pattern[i] = 'B'
                pattern[i+1] = 'B'
                steps.append(i+1)

    print(count)
    if count>0:
        for i in steps:
            print(i, end = " ")
        print("")
    #print(pattern)









if __name__ == "__main__":
    main()
