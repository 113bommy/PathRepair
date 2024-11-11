_, sa = input(), input()
print(
    "No" if ("11" in sa or "000" in sa or sa.startswith("00") or sa.endswith("00")) or sa == "0" else "Yes")
