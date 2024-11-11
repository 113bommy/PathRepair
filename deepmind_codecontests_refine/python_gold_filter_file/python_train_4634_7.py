n = input()
for i in range (len(n)-4):
    if n[i] == 'h':
        for j in range (i+1, len(n)-3):
            if n[j] == 'e':
                for k in range (j+1, len(n)-2):
                    if n[k] == 'l':
                        for l in range (k+1, len(n)-1):
                            if n[l] == 'l':
                                for p in range (l+1, len(n)):
                                    if n[p] == 'o':
                                        print ("YES")
                                        exit()
print ("NO")