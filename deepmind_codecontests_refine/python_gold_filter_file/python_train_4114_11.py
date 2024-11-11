words = input().replace(';',',').split(',')
ints = [word for word in words if word.isdigit() and (word[0] != '0' or len(word) == 1)]
non_ints = [i for i in words if i not in ints]
print("\"" + ",".join(ints) + "\"" if len(ints) != 0 else "-")
print("\"" + ",".join(non_ints) + "\"" if len(non_ints) else "-")