n = input()
if n.replace("144","zzz").replace("14","zz").replace("1","z").count("z") == len(n):
    print ("YES")
else:
    print ("NO")
