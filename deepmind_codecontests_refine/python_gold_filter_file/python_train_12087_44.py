seq_len = int(input())
seq = [int(element) for element in input().split() if element == "1"]
if seq:
    print("HARD")
else:
    print("EASY")