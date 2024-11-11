import sys
print("\n".join((" ".join(str(2**i)for i, n in enumerate(bin(int(s))[:1:-1])if n=="1")for s in sys.stdin.readlines())))
