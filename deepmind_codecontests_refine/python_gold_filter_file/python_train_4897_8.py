num = int(input())
res = " ".join([str(x) for x in range(1, num+1) if x % 3 == 0 or str(x).find("3") != -1])
print(" {}".format(res))